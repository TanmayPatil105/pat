/* pat.c
 *
 * Copyright 2023 Tanmay Patil <tanmaynpatil105@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <getopt.h>
#include "config.h"
#include "file.h"

#define PROGRAM_NAME "pat"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void
usage (int status)
{
  if (status != EXIT_SUCCESS)
    {
      printf ("Try '%s -h' for more information.\n", PROGRAM_NAME);
      exit (status);
    }

  printf ("Usage: %s FILE....\n", PROGRAM_NAME);
  printf ("Create files with default boilerplate code written in them.\n");

  printf ("\nA FILE argument that exists is not overwritten.\
 Use -o FILE argument to overwrite\n");

  if (status == EXIT_SUCCESS)
    {
      exit (EXIT_SUCCESS);
    }
}

void
pat_write (FILE *fd, const char *file_name)
{
  FileExtension fext = get_file_extension (file_name);

  if (fext == FILE_EXTENSION_NONE)
    {
      return;
    }
 
  char *code = get_extension_code (fext);
  fwrite (code, 1, strlen(code), fd);
}

static bool
pat (const char *file_name, bool overwrite)
{
  FILE *fd = NULL;
  const char *mode = NULL;

  if ((access (file_name, W_OK) == 0) &&
       overwrite)
    {
      mode = "w";
      fd = fopen (file_name, mode); 
    }
  else if ((access (file_name, F_OK)) != 0)
    {
      mode = "w+";
      fd = fopen (file_name, mode); 
    }

  if (fd == NULL)
    {
      return false; 
    }

  pat_write (fd, file_name);

  fclose (fd);

  return true;
}

int
main (int argc, char *argv[])
{
  int opt;
  bool ok = true;
  bool overwrite = false;
  bool show_version = false;

  while ((opt = getopt(argc, argv, "hov")) != -1)
  {
    switch (opt)
      {
        case 'h':
	  usage(EXIT_SUCCESS);
          break;
	
	case 'o':
	  overwrite = true;
	  break;

	case 'v':
	  show_version = true;
	  break;

       default:
         usage (EXIT_FAILURE);
     }
  }

  if (show_version == true)
    {
      printf ("%s\n", VERSION);
      exit (EXIT_SUCCESS);
    }

  if (optind == argc)
    {
      perror ("missing file operand");
      usage (EXIT_FAILURE);
    }

  for (; optind < argc; ++optind)
    ok &= pat (argv[optind], overwrite);

  exit (ok ? EXIT_SUCCESS : EXIT_FAILURE);
}

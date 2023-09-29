/* file.c
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
#include <string.h>
#include "file.h"

typedef struct { 
  char *key;
  FileExtension fext;
} m_item;

static m_item lookupmap[] = {
    { "c", FILE_EXTENSION_C },
    { "py", FILE_EXTENSION_PYTHON },
    { "go", FILE_EXTENSION_GO },
    { "cpp", FILE_EXTENSION_CPP },
    { "cc", FILE_EXTENSION_CPP },
    { "html", FILE_EXTENSION_HTML },
};

#define NEXT (sizeof(lookupmap)/sizeof(m_item))

static char *codes [N_FILE_EXTENSION];

static const char*
_get_file_extension (const char *file_name)
{
  const char *period = strrchr (file_name, '.');
  if (!period ||
      period == file_name)
    {
      return "";
    }

 return period + 1;
}

static FileExtension
key_from_extension (const char *key)
{
  int i;

  for (i = 0; i < (int)NEXT; i++)
    {
      m_item item = lookupmap[i];
      if (strcmp (item.key, key) == 0)
        return item.fext;
    }

  return FILE_EXTENSION_NONE;
}

FileExtension
get_file_extension (const char *file_name)
{
  const char *ext = _get_file_extension(file_name);
  
  return key_from_extension (ext);
}

char*
get_extension_code (FileExtension fext)
{
  codes [FILE_EXTENSION_C] = "#include <stdio.h>\n\nint main() {\n  return 0;\n}\n";
  codes [FILE_EXTENSION_PYTHON] = "\ndef main():\n\treturn 0\n\nif __name__ == '__main__':\n\tmain()";
  codes [FILE_EXTENSION_GO] = "package main\n\nfunc main(){\n\n}";
  codes [FILE_EXTENSION_CPP] = "#include <iostream>\n\nusing namespace std;\n\nint main(){\n\treturn 0;\n}";
  codes [FILE_EXTENSION_HTML] = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n\t<meta charset=\"UTF-8\">\n\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\t<title>Document</title>\n</head>\n<body>\n\n</body>\n</html>";

  return codes[fext]; 
}

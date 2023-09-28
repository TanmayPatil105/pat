/* file.h
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

#pragma once

typedef enum {
  FILE_EXTENSION_C,
  FILE_EXTENSION_PYTHON,
  FILE_EXTENSION_GO,
  FILE_EXTENSION_CPP,
  FILE_EXTENSION_HTML,
  FILE_EXTENSION_NONE,
  N_FILE_EXTENSION,
} FileExtension;

FileExtension 	get_file_extension (const char *file_name);
char * 		get_extension_code (FileExtension fext); 

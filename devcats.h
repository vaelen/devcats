/******
This file is part of devcats.

Copyright 2017, Andrew Young <andrew@vaelen.org>

    Vaelen/DB is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

    Vaelen/DB is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
along with devcats.  If not, see <http://www.gnu.org/licenses/>.
******/

#ifndef DEV_CATS_LIBRARY_H
#define DEV_CATS_LIBRARY_H

#include <linux/compiler.h> /* __must_check */

__must_check int register_device(void); /* 0 if Ok*/

void 			 unregister_device(void);

#endif

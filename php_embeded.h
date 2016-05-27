/*
** ZABBIX PHP Lodable Module
** Copyright (C) 2007-2016 Mathieu CARBONNEAUX
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
*/


#ifndef PHP_EMBEDED_H
#define PHP_EMBEDED_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#undef PACKAGE_NAME

#include "zend_interfaces.h"
#include "php_version.h"

#define HARDCODED_INI			\
	"html_errors=0\n"		\
	"register_argc_argv=1\n"	\
	"implicit_flush=1\n"		\
	"output_buffering=0\n"		\
	"max_execution_time=0\n"	\
	"max_input_time=-1\n"

extern zend_class_entry *default_exception_ce;

int 		php_embed_rinit(TSRMLS_D);
ZEND_API void 	php_embed_excute(zval *exception TSRMLS_DC);
ZEND_API int 	php_embed_eval_string(char *str, zval *retval_ptr, char *string_name TSRMLS_DC);
void 		php_embed_mshutdown(TSRMLS_D);
void 		php_embed_rshutdown(TSRMLS_D);

#endif

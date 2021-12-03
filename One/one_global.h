#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ONE_LIB)
#  define ONE_EXPORT Q_DECL_EXPORT
# else
#  define ONE_EXPORT Q_DECL_IMPORT
# endif
#else
# define ONE_EXPORT
#endif

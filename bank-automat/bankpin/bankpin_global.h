#ifndef BANKPIN_GLOBAL_H
#define BANKPIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BANKPIN_LIBRARY)
#define BANKPIN_EXPORT Q_DECL_EXPORT
#else
#define BANKPIN_EXPORT Q_DECL_IMPORT
#endif

#endif // BANKPIN_GLOBAL_H

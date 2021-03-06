// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://polarphp.org/LICENSE.txt for license information
// See https://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2018/12/25.

#include "polarphp/runtime/internal/DepsZendVmHeaders.h"
#include "polarphp/runtime/PhpDefs.h"
#include "polarphp/vm/Callable.h"

namespace polar {
namespace runtime {

VmExtensionInitFuncType sg_vmExtensionInitHook = nullptr;

bool php_register_internal_extensions()
{
   if (sg_vmExtensionInitHook != nullptr) {
      if (!sg_vmExtensionInitHook()) {
         return false;
      }
   }
   return true;
}

} // runtime
} // polar

/*
 * Copyright (c) 2008, 2013, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#include <string.h>

#include "jni.h"
#include "jni_util.h"
#include "dlfcn.h"

jstring nativeNewStringPlatform(JNIEnv *env, const char *str) {
    return NULL;
}

char* nativeGetStringPlatformChars(JNIEnv *env, jstring jstr, jboolean *isCopy) {
    return NULL;
}

void* getProcessHandle() {
    static void *procHandle = NULL;
    if (procHandle != NULL) {
        return procHandle;
    }
#ifdef __APPLE__
    procHandle = (void*)dlopen(NULL, RTLD_FIRST);
#else
    procHandle = (void*)dlopen(NULL, RTLD_LAZY);
#endif
    return procHandle;
}

void buildJniFunctionName(const char *sym, const char *cname,
                          char *jniEntryName) {
    strcpy(jniEntryName, sym);
    if (cname != NULL) {
        strcat(jniEntryName, "_");
        strcat(jniEntryName, cname);
    }
}


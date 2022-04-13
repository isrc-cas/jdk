/*
 * Copyright (c) 1999, 2020, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
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
 *
 */

#ifndef OS_CPU_WINDOWS_X86_THREAD_WINDOWS_X86_HPP
#define OS_CPU_WINDOWS_X86_THREAD_WINDOWS_X86_HPP

 private:
  // On windows, in the stubGenerator, there's nowhere to save callee saved regs
  address          _windows_saved_rsi;
  address          _windows_saved_rdi;

  void pd_initialize() {
    _anchor.clear();

    _windows_saved_rsi = NULL;
    _windows_saved_rdi = NULL;
  }

  frame pd_last_frame(bool allowUnsafe = false);

 public:
  static ByteSize last_Java_fp_offset()          {
    return byte_offset_of(JavaThread, _anchor) + JavaFrameAnchor::last_Java_fp_offset();
  }

  bool pd_get_top_frame_for_signal_handler(frame* fr_addr, void* ucontext,
    bool isInJava);

   bool pd_get_top_frame_for_profiling(frame* fr_addr, void* ucontext, bool isInJava);

  static ByteSize windows_saved_rsi_offset() { return byte_offset_of(JavaThread, _windows_saved_rsi); }
  static ByteSize windows_saved_rdi_offset() { return byte_offset_of(JavaThread, _windows_saved_rdi); }
private:
  bool pd_get_top_frame(frame* fr_addr, void* ucontext, bool isInJava, bool allowUnsafe);

#endif // OS_CPU_WINDOWS_X86_THREAD_WINDOWS_X86_HPP

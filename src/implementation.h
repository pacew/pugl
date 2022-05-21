// Copyright 2012-2022 David Robillard <d@drobilla.net>
// SPDX-License-Identifier: ISC

#ifndef PUGL_IMPLEMENTATION_H
#define PUGL_IMPLEMENTATION_H

#include "attributes.h"
#include "types.h"

#include "pugl/pugl.h"

#include <stddef.h>
#include <stdint.h>

PUGL_BEGIN_DECLS

/// Set `blob` to `data` with length `len`, reallocating if necessary
PuglStatus
puglSetBlob(PuglBlob* dest, const void* data, size_t len);

/// Reallocate and set `*dest` to `string`
void
puglSetString(char** dest, const char* string);

/// Allocate and initialise world internals (implemented once per platform)
PuglWorldInternals*
puglInitWorldInternals(PuglWorldType type, PuglWorldFlags flags);

/// Destroy and free world internals (implemented once per platform)
void
puglFreeWorldInternals(PuglWorld* world);

/// Allocate and initialise view internals (implemented once per platform)
PuglInternals*
puglInitViewInternals(PuglWorld* world);

/// Destroy and free view internals (implemented once per platform)
void
puglFreeViewInternals(PuglView* view);

/// Return the Unicode code point for `buf` or the replacement character
uint32_t
puglDecodeUTF8(const uint8_t* buf);

/// Dispatch an event with a simple `type` to `view`
PuglStatus
puglDispatchSimpleEvent(PuglView* view, PuglEventType type);

/// Process configure event while already in the graphics context
PUGL_WARN_UNUSED_RESULT
PuglStatus
puglConfigure(PuglView* view, const PuglEvent* event);

/// Process expose event while already in the graphics context
PUGL_WARN_UNUSED_RESULT
PuglStatus
puglExpose(PuglView* view, const PuglEvent* event);

/// Dispatch `event` to `view`, entering graphics context if necessary
PuglStatus
puglDispatchEvent(PuglView* view, const PuglEvent* event);

/*

/// Return a pointer to the blob for data retrieved from the given clipboard
PuglBlob*
puglGetClipboardBlob(PuglView* view);

/// Set internal (stored in view) clipboard contents
const void*
puglGetInternalClipboard(const PuglView* view, const char** type, size_t* len);

/// Set internal (stored in view) clipboard contents
PUGL_WARN_UNUSED_RESULT
PuglStatus
puglSetInternalClipboard(PuglView*   view,
                         const char* type,
                         const void* data,
                         size_t      len);

*/

PUGL_END_DECLS

#endif // PUGL_IMPLEMENTATION_H

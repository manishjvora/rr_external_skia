/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorMatrixFilter_DEFINED
#define SkColorMatrixFilter_DEFINED

#include "SkColorFilter.h"

class SK_API SkColorMatrixFilterRowMajor255 : public SkColorFilter {
public:
    explicit SkColorMatrixFilterRowMajor255(const SkScalar array[20]);

    /** Creates a color matrix filter that returns the same value in all four channels. */
    static SkColorFilter* CreateSingleChannelOutput(const SkScalar row[5]);

    void filterSpan(const SkPMColor src[], int count, SkPMColor[]) const override;
    void filterSpan4f(const SkPM4f src[], int count, SkPM4f[]) const override;
    uint32_t getFlags() const override;
    bool asColorMatrix(SkScalar matrix[20]) const override;
    SkColorFilter* newComposed(const SkColorFilter*) const override;

#if SK_SUPPORT_GPU
    const GrFragmentProcessor* asFragmentProcessor(GrContext*) const override;
#endif

    SK_TO_STRING_OVERRIDE()

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkColorMatrixFilter)

protected:
    void flatten(SkWriteBuffer&) const override;

private:
    SkColorMatrixFilterRowMajor255() {};

    SkScalar        fMatrix[20];
    float           fTranspose[20]; // for Sk4s
    uint32_t        fFlags;

    void initState();

    typedef SkColorFilter INHERITED;
};

#endif

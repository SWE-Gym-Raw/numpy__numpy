/*@targets
 * $maxopt $keep_baseline
 * avx512_skx avx2
 */
// policy $keep_baseline is used to avoid skip building avx512_skx
// when its part of baseline features (--cpu-baseline), since
// 'baseline' option isn't specified within targets.

#include "x86_simd_qsort.hpp"
#ifndef __CYGWIN__

#if defined(NPY_HAVE_AVX512_SKX)
    #include "x86-simd-sort/src/avx512-32bit-qsort.hpp"
    #include "x86-simd-sort/src/avx512-64bit-qsort.hpp"
    #include "x86-simd-sort/src/avx512-64bit-argsort.hpp"
#elif defined(NPY_HAVE_AVX2)
    #include "x86-simd-sort/src/avx2-32bit-qsort.hpp"
    #include "x86-simd-sort/src/avx2-64bit-qsort.hpp"
#endif

namespace np { namespace qsort_simd {

#if defined(NPY_HAVE_AVX512_SKX) || defined(NPY_HAVE_AVX2)
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(int32_t *arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num);
#else
    avx2_qselect(arr, kth, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(uint32_t *arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num);
#else
    avx2_qselect(arr, kth, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(int64_t*arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num);
#else
    avx2_qselect(arr, kth, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(uint64_t*arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num);
#else
    avx2_qselect(arr, kth, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(float *arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num, true);
#else
    avx2_qselect(arr, kth, num, true);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSelect)(double *arr, npy_intp num, npy_intp kth)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qselect(arr, kth, num, true);
#else
    avx2_qselect(arr, kth, num, true);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(int32_t *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num);
#else
    avx2_qsort(arr, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(uint32_t *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num);
#else
    avx2_qsort(arr, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(int64_t *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num);
#else
    avx2_qsort(arr, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(uint64_t *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num);
#else
    avx2_qsort(arr, num);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(float *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num, true);
#else
    avx2_qsort(arr, num, true);
#endif
}
template<> void NPY_CPU_DISPATCH_CURFX(QSort)(double *arr, npy_intp num)
{
#if defined(NPY_HAVE_AVX512_SKX)
    avx512_qsort(arr, num, true);
#else
    avx2_qsort(arr, num, true);
#endif
}
#endif // NPY_HAVE_AVX512_SKX || NPY_HAVE_AVX2

}} // namespace np::qsort_simd

#endif // __CYGWIN__

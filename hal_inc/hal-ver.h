#ifndef __HAL_LIBS_HEADER__
#define __HAL_LIBS_HEADER__

#define HAL_LIBS_VER_MAJOR 1       /* 0 <= major < 16  */
#define HAL_LIBS_VER_MINOR 0       /* 0 <= minor < 256 */
#define HAL_LIBS_VER_PATCH 1       /* 0 <= patch < 256 */
#define HAL_LIBS_VER_SUBMISSION 0  /* 0 <= submission < 4096 */

#define HAL_LIBS_VER_MAJOR_WIDTH 4
#define HAL_LIBS_VER_MINOR_WIDTH 8
#define HAL_LIBS_VER_PATCH_WIDTH 8
#define HAL_LIBS_VER_SUBMISSION_WIDTH 12

#define HAL_LIBS_VER_MAJOR_SHIFT (32 - HAL_LIBS_VER_MAJOR_WIDTH)
#define HAL_LIBS_VER_MINOR_SHIFT                                            \
    (HAL_LIBS_VER_MAJOR_SHIFT - HAL_LIBS_VER_MINOR_WIDTH)
#define HAL_LIBS_VER_PATCH_SHIFT                                            \
    (HAL_LIBS_VER_MINOR_SHIFT - HAL_LIBS_VER_PATCH_WIDTH)

#define HAL_LIBS_VER(major, minor, patch, submission)                       \
    (((major) << HAL_LIBS_VER_MAJOR_SHIFT) +                                \
     ((minor) << HAL_LIBS_VER_MINOR_SHIFT) +                                \
     ((patch) << HAL_LIBS_VER_PATCH_SHIFT) + (submission))

#define HAL_LIBS_VER_CUR                                                    \
    HAL_LIBS_VER(HAL_LIBS_VER_MAJOR, HAL_LIBS_VER_MINOR,              \
					HAL_LIBS_VER_PATCH, HAL_LIBS_VER_SUBMISSION)

#endif /* __HAL_LIBS_HEADER__ */

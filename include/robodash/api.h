/**
 * @file api.h
 * @brief API entrypoint for robodash
 *
 * Includes all necessary functions to use robodash.
 */

#pragma once

#define ROBODASH
#define RD_VERSION_MAJOR 2
#define RD_VERSION_MINOR 2
#define RD_VERSION_PATCH 0

#include "liblvgl/lvgl.h"

// ========================== Check Compatibility ========================== //

#if (LV_VERSION_CHECK(8, 3, 0) == 0)
#error "LVGL version incompatible with robodash (Requires >= 8.3.X)"
#endif

#ifndef LV_FONT_MONTSERRAT_12
#error "LVGL install incompatible with robodash, missing font: Montserrat 12"
#endif

#ifndef LV_FONT_MONTSERRAT_14
#error "LVGL install incompatible with robodash, missing font: Montserrat 14"
#endif

#ifndef LV_FONT_MONTSERRAT_16
#error "LVGL install incompatible with robodash, missing font: Montserrat 16"
#endif

// ============================ Include Library ============================ //

#include "core.h"

#ifdef __cplusplus
#include "views/console.hpp"
#include "views/image.hpp"
#include "views/selector.hpp"
#endif
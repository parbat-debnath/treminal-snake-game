// style.h
#pragma once

/* ============================================================================
 * TEXT ATTRIBUTES & STYLES
 * ============================================================================ */
#define STYLE_RESET         "\033[0m"
#define STYLE_BOLD          "\033[1m"
#define STYLE_DIM           "\033[2m"
#define STYLE_ITALIC        "\033[3m"
#define STYLE_UNDERLINE     "\033[4m"
#define STYLE_BLINK         "\033[5m"
#define STYLE_REVERSE       "\033[7m"
#define STYLE_HIDDEN        "\033[8m"
#define STYLE_STRIKETHROUGH "\033[9m"

/* ============================================================================
 * FOREGROUND COLORS (Standard & High Intensity)
 * ============================================================================ */
#define FG_BLACK            "\033[30m"
#define FG_RED              "\033[31m"
#define FG_GREEN            "\033[32m"
#define FG_YELLOW           "\033[33m"
#define FG_BLUE             "\033[34m"
#define FG_MAGENTA          "\033[35m"
#define FG_CYAN             "\033[36m"
#define FG_WHITE            "\033[37m"
#define FG_DEFAULT          "\033[39m"

/* High Intensity / Bright Foreground */
#define FG_BRIGHT_BLACK     "\033[90m"
#define FG_BRIGHT_RED       "\033[91m"
#define FG_BRIGHT_GREEN     "\033[92m"
#define FG_BRIGHT_YELLOW    "\033[93m"
#define FG_BRIGHT_BLUE      "\033[94m"
#define FG_BRIGHT_MAGENTA   "\033[95m"
#define FG_BRIGHT_CYAN      "\033[96m"
#define FG_BRIGHT_WHITE     "\033[97m"

/* ============================================================================
 * BACKGROUND COLORS (Standard & High Intensity)
 * ============================================================================ */
#define BG_BLACK            "\033[40m"
#define BG_RED              "\033[41m"
#define BG_GREEN            "\033[42m"
#define BG_YELLOW           "\033[43m"
#define BG_BLUE             "\033[44m"
#define BG_MAGENTA          "\033[45m"
#define BG_CYAN             "\033[46m"
#define BG_WHITE            "\033[47m"
#define BG_DEFAULT          "\033[49m"

/* High Intensity / Bright Background */
#define BG_BRIGHT_BLACK     "\033[100m"
#define BG_BRIGHT_RED       "\033[101m"
#define BG_BRIGHT_GREEN     "\033[102m"
#define BG_BRIGHT_YELLOW    "\033[103m"
#define BG_BRIGHT_BLUE      "\033[104m"
#define BG_BRIGHT_MAGENTA   "\033[105m"
#define BG_BRIGHT_CYAN      "\033[106m"
#define BG_BRIGHT_WHITE     "\033[107m"

/* ============================================================================
 * DYNAMIC 256-COLOR & TRUECOLOR (RGB) MACROS
 * ============================================================================ */
/* Pass color codes from 0 to 255 */
#define FG_256(code)        "\033[38;5;" #code "m"
#define BG_256(code)        "\033[48;5;" #code "m"

/* Pass 8-bit RGB values (0 to 255) */
#define FG_RGB(r, g, b)     "\033[38;2;" #r ";" #g ";" #b "m"
#define BG_RGB(r, g, b)     "\033[48;2;" #r ";" #g ";" #b "m"

/* ============================================================================
 * CURSOR & TERMINAL CONTROL
 * ============================================================================ */
#define TERM_CLEAR          "\033[2J\033[H"
#define TERM_CLEAR_LINE     "\033[2K\r"
#define CURSOR_HIDE         "\033[?25l"
#define CURSOR_SHOW         "\033[?25h"
#define CURSOR_UP(n)        "\033[" #n "A"
#define CURSOR_DOWN(n)      "\033[" #n "B"
#define CURSOR_FORWARD(n)   "\033[" #n "C"
#define CURSOR_BACK(n)      "\033[" #n "D"

/* ============================================================================
 * UTILITY HELPER MACROS
 * ============================================================================ */
/* Wraps string literal in a style and automatically resets formatting afterward */
#define STYLED_TEXT(style, text) style text STYLE_RESET
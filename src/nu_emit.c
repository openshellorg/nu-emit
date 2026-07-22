#include "nu_emit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int nu_emit_need_comma = 0;

static void nu_emit_comma(void) {
  if (nu_emit_need_comma) {
    fputc(',', stdout);
  }
  nu_emit_need_comma = 1;
}

static void nu_emit_json_str(const char *s) {
  fputc('"', stdout);
  if (!s) {
    fputc('"', stdout);
    return;
  }
  for (const unsigned char *p = (const unsigned char *)s; *p; ++p) {
    switch (*p) {
      case '"':  fputs("\\\"", stdout); break;
      case '\\': fputs("\\\\", stdout); break;
      case '\b': fputs("\\b", stdout); break;
      case '\f': fputs("\\f", stdout); break;
      case '\n': fputs("\\n", stdout); break;
      case '\r': fputs("\\r", stdout); break;
      case '\t': fputs("\\t", stdout); break;
      default:
        if (*p < 0x20) {
          fprintf(stdout, "\\u%04x", (unsigned)*p);
        } else {
          fputc(*p, stdout);
        }
        break;
    }
  }
  fputc('"', stdout);
}

void nu_emit_row_begin(void) {
  nu_emit_need_comma = 0;
  fputc('{', stdout);
}

void nu_emit_row_end(void) {
  fputc('}', stdout);
  fputc('\n', stdout);
  fflush(stdout);
  nu_emit_need_comma = 0;
}

void nu_emit_field_str(const char *key, const char *value) {
  nu_emit_comma();
  nu_emit_json_str(key);
  fputc(':', stdout);
  nu_emit_json_str(value);
}

void nu_emit_field_i64(const char *key, int64_t value) {
  nu_emit_comma();
  nu_emit_json_str(key);
  fprintf(stdout, ":%lld", (long long)value);
}

void nu_emit_field_f64(const char *key, double value) {
  nu_emit_comma();
  nu_emit_json_str(key);
  fprintf(stdout, ":%.17g", value);
}

void nu_emit_field_bool(const char *key, int value) {
  nu_emit_comma();
  nu_emit_json_str(key);
  fputs(value ? ":true" : ":false", stdout);
}

#ifndef NU_EMIT_H
#define NU_EMIT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Begin a JSON object on stdout. */
void nu_emit_row_begin(void);

/* End the object, write '\n', fflush(stdout). */
void nu_emit_row_end(void);

void nu_emit_field_str(const char *key, const char *value);
void nu_emit_field_i64(const char *key, int64_t value);
void nu_emit_field_f64(const char *key, double value);
void nu_emit_field_bool(const char *key, int value); /* 0 = false, else true */

#ifdef __cplusplus
}
#endif

#endif /* NU_EMIT_H */

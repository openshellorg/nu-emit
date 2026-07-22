#include "nu_emit.h"

int main(void) {
  nu_emit_row_begin();
  nu_emit_field_str("status", "running");
  nu_emit_field_i64("pid", 4012);
  nu_emit_field_i64("memory_mb", 128);
  nu_emit_row_end();

  nu_emit_row_begin();
  nu_emit_field_str("status", "idle");
  nu_emit_field_i64("pid", 5104);
  nu_emit_field_i64("memory_mb", 64);
  nu_emit_row_end();
  return 0;
}

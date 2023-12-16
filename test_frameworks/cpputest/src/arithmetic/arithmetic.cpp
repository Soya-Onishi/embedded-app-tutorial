#include <stdint.h>

/**
 * @brief 加算処理。
 * オーバーフローなどが発生しても特に何も対処せず、そのまま返す。
 * @param a
 * @param b
 * @return uint32_t 加算結果。
 */
uint32_t add(const uint32_t a, const uint32_t b) { return a + b; }

/**
 * @brief 加算処理。
 * 加算処理の結果がオーバーフローした場合は符号なし32bit整数の最大値（0xFFFF_FFFF）を返す。
 *
 * @param a
 * @param b
 * @return uint32_t 加算結果。オーバーフローした場合は0xFFFF_FFFF。
 */
uint32_t saturating_add(const uint32_t a, const uint32_t b) {
  const uint32_t result = a + b;

  if (result < a) {
    return 0xFFFFFFFF;
  }

  return result;
}
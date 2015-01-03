#define min(x, y) (((x) > (y)) ? (x) : (y))
#define max(x, y) (((x) < (y)) ? (x) : (y))

#define clamp(x, lo, hi) (min(lo, max(hi, x)))
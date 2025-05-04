#define TEST_BASE_ADDR 0xF780
#define WRITE_TEST(n) (*(volatile unsigned char*)(TEST_BASE_ADDR + (n)) = (n))

void test_addition(void)
{
  if ((unsigned char)(5 + 3) == 8)
    WRITE_TEST(1);
}

void test_subtraction(void)
{
  if ((unsigned char)(10 - 7) == 3)
    WRITE_TEST(2);
}

void test_multiplication(void)
{
  if ((unsigned char)(6 * 4) == 24)
    WRITE_TEST(3);
}

void test_division(void)
{
  if ((unsigned char)(12 / 3) == 4)
    WRITE_TEST(4);
}

void test_logical_and(void)
{
  if ((unsigned char)(0x0F & 0xF0) == 0x00)
    WRITE_TEST(5);
}

void test_logical_or(void)
{
  if ((unsigned char)(0x0F | 0xF0) == 0xFF)
    WRITE_TEST(6);
}

void test_bitwise_not(void)
{
  if ((unsigned char)(~0x0F) == 0xF0)
    WRITE_TEST(7);
}

void test_comparison(void)
{
  if (5 == 5)
    WRITE_TEST(8);
}

void test_branch(void)
{
  if (5 > 3)
    WRITE_TEST(9);
}

void test_loop(void)
{
  unsigned char sum = 0;
  int i;
  for (i = 0; i < 5; i++)
    sum += i;
  if (sum == 10)
    WRITE_TEST(10);
}

void test_increment(void)
{
  unsigned char x = 1;
  x++;
  if (x == 2)
    WRITE_TEST(11);
}

void test_decrement(void)
{
  unsigned char x = 3;
  x--;
  if (x == 2)
    WRITE_TEST(12);
}

void test_xor(void)
{
  if ((unsigned char)(0xAA ^ 0xFF) == 0x55)
    WRITE_TEST(13);
}

void test_shift_left(void)
{
  if ((unsigned char)(1 << 3) == 8)
    WRITE_TEST(14);
}

void test_shift_right(void)
{
  if ((unsigned char)(8 >> 2) == 2)
    WRITE_TEST(15);
}

void test_assign(void)
{
  unsigned char x = 42;
  if (x == 42)
    WRITE_TEST(16);
}

void test_zero_compare(void)
{
  unsigned char x = 0;
  if (x == 0)
    WRITE_TEST(17);
}

void test_nonzero_compare(void)
{
  unsigned char x = 5;
  if (x != 0)
    WRITE_TEST(18);
}

void test_unsigned_wraparound(void)
{
  unsigned char x = 255;
  x++;
  if (x == 0)
    WRITE_TEST(19);
}

void test_large_addition(void)
{
  unsigned char x = 200;
  x += 100;
  if (x == 44)
    WRITE_TEST(20);
}

int main(void)
{
  test_addition();
  test_subtraction();
  test_multiplication();
  test_division();
  test_logical_and();
  test_logical_or();
  test_bitwise_not();
  test_comparison();
  test_branch();
  test_loop();
  test_increment();
  test_decrement();
  test_xor();
  test_shift_left();
  test_shift_right();
  test_assign();
  test_zero_compare();
  test_nonzero_compare();
  test_unsigned_wraparound();
  test_large_addition();

  while(1);

  return 0;
}

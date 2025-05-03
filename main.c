#define TEST_BASE_ADDR 0xF780

#define WRITE_TEST(test_num) (*(volatile unsigned char *)(TEST_BASE_ADDR + test_num) = test_num)

void test_addition(void) {
  volatile unsigned char result;
  result = 5 + 3;
  WRITE_TEST(1);
}

void test_subtraction(void) {
  volatile unsigned char result;
  result = 10 - 7;
  WRITE_TEST(2);
}

void test_multiplication(void) {
  volatile unsigned char result;
  result = 6 * 4;
  WRITE_TEST(3);
}

void test_division(void) {
  volatile unsigned char result;
  result = 12 / 3;
  WRITE_TEST(4);
}

void test_logical_and(void) {
  volatile unsigned char result;
  result = 0x0F & 0xF0;
  WRITE_TEST(5);
}

void test_logical_or(void) {
  volatile unsigned char result;
  result = 0x0F | 0xF0;
  WRITE_TEST(6);
}

void test_bitwise_not(void) {
  volatile unsigned char result;
  result = ~0x0F;
  WRITE_TEST(7);
}

void test_comparison(void) {
  volatile unsigned char result;
  result = (5 == 5);  // This should be 1 (true)
  WRITE_TEST(8);
}

void test_branch(void) {
  volatile unsigned char result;
  if (5 > 3) {
    result = 1;
  } else {
    result = 0;
  }
  WRITE_TEST(9);
}

void test_loop(void) {
  volatile unsigned char result = 0;
  int i;

  for (i = 0; i < 5; i++) {
    result += i;
  }
  WRITE_TEST(10);
}

void test(void)
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
}

int main(void)
{
  test();
  return 0;
}

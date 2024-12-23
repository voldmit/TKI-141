
enum fill
{
	manual,
	random
};

int input();

size_t input_size();

enum fill input_choice();

int* get_array(const size_t size);

void check_array(const int* const array);

void print_array(const int* const array, const size_t size);

void manual_fill(int* const array, const size_t size);

void random_fill(int* const array, const size_t size, const int min, const int max);

void print_array(const int* const array, const size_t size);

void index36(const int* const array, const size_t size);

void sumchet(const int* const array, const size_t size);

void zamena(const int* const array, const size_t size);

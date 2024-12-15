
enum fill
{
	manual,
	random
};

int input(const char* message);

size_t input_size(const char* message);

enum fill input_choice(const char* message);

int* get_array(const size_t size);

void check_array(const int* const array);

void print_array(const int* const array, const size_t size, const char* message);

void manual_fill(int* const array, const size_t size);

void random_fill(int* const array, const size_t size, const int min, const int max);

void index36(const int* const array, const size_t size);

void sumchet(const int* const array, const size_t size);

void zamena(const int* const array, const size_t size);
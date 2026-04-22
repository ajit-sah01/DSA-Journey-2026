#include <iostream>
#include <string>
#include <cstddef>

// --- Custom Fast Allocator ---
const size_t BUFFER_SIZE = 0x6fafffff; // ~1.8 GB
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *operator new(size_t size)
{
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void *ptr) noexcept {}
void operator delete(void *ptr, std::size_t) noexcept {}
void operator delete[](void *ptr) noexcept {}

// --- Your Solution ---
class Solution
{
public:
    int titleToNumber(const string &columnTitle)
    { // Added 'const' and '&'
        long long res = 0;
        for (char c : columnTitle)
        {
            res = res * 26 + (c - 'A' + 1);
        }
        return (int)res;
    }
};
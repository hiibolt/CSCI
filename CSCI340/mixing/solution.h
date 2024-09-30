#include <queue>
#include <algorithm>

struct Token {
    int value;
    int original_index;
};

template <typename ForwardIterator>
void move_number_forward ( 
    ForwardIterator begin,
    ForwardIterator end,
    int index,
    int number_forward,
    int length
) {
    int current_index = index;
    // If the element is not at the end, move it forward by repeatedly swapping
    //  it with the next element
    for (int i = 0; i < number_forward; i++) {
        // Get the next index
        int next_index = current_index + 1;

        // If the next index is out of bounds, use the last element
        if (next_index >= length) {
            next_index = length - 1;
        }
        
        //std::cout << "Swapping " << current_index << " with " << next_index << std::endl;

        // Get the iterator of the current and next element
        auto current_it = begin;
        std::advance(current_it, current_index);
        auto next_it = begin;
        std::advance(next_it, next_index);

        // Swap the two elements
        std::iter_swap(current_it, next_it);
        

        // Update the current index
        current_index = next_index;
    }
}

template <typename ForwardIterator>
void move_number_backward ( 
    ForwardIterator begin,
    ForwardIterator end,
    int index,
    int num_backward,
    int length
) {
    int current_index = index;
    // If the element is not at the end, move it forward by repeatedly swapping
    //  it with the next element
    for (int i = 0; i < num_backward; i++) {
        // Get the next index
        int next_index = current_index - 1;

        // If it's out of bounds, use the last element
        if (next_index < 0)
            next_index = length - 1;
        
        //std::cout << "Swapping " << current_index << " with " << next_index << std::endl;

        // Get the iterator of the current and next element
        auto current_it = begin;
        std::advance(current_it, current_index);
        auto next_it = begin;
        std::advance(next_it, next_index);

        // Swap the two elements
        std::iter_swap(current_it, next_it);
        

        // Update the current index
        current_index = next_index;
    }
}

template <typename ForwardIterator>
void mixNumbers(ForwardIterator begin, ForwardIterator end)
{
    std::vector<int> original_numbers;
    std::vector<Token> tokens;
    
    // Load the array into the queue
    for (auto it = begin; it != end; ++it)
        original_numbers.push_back(*it);

    // Load the array into the vector
    int len = 0;
    for (auto it = begin; it != end; ++it, ++len)
        tokens.push_back({*it, len});
    
    //std::cout << "Length: " << len << std::endl;

    //move_number_forward(&begin, &end, 0, 5, len);

    // Work one by one on each element based on its original index
    for ( int i = 0; i < len; i++ ) {
        //std::cout << "Working " << i << std::endl;

        // Find the element with the original index
        auto it = std::find_if(tokens.begin(), tokens.end(), [i](Token t) {
            return t.original_index == i;
        });

        // Get the index of the element
        int index = std::distance(tokens.begin(), it);

        // Get the value of the element
        int value = it->value;

        // If it is positive, move it forward, otherwise move it backward
        if (value > 0) {
            move_number_forward(tokens.begin(), tokens.end(), index, value, len);
        } else if (value < 0) {
            move_number_backward(tokens.begin(), tokens.end(), index, value, len);
        }
    
        // Debug print the token's values
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            //std::cout << it->value << " ";
        }
        //std::cout << std::endl; 
    }

    //std::cout << "ended" << std::endl;
}

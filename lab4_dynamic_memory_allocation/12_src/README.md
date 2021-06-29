template based solution. provides some extra implementations:
1. move-semantics;
2. strong exception-safety;
3. typedefs;
4. default std::allocator (using std::allocator_traits);
5. some extra vector-based methods(reserve, push_back, size, capacity);

Valgrind flags:
--leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=no

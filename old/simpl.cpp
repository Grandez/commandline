#include "type_traits"

namespace spimpl {
    namespace details {
        template<class T>
        void default_delete(T *p) noexcept {
            static_assert(sizeof(T) > 0, "default_delete cannot delete incomplete type");
            static_assert(!std::is_void<T>::value, "default_delete cannot delete incomplete type");
            delete p;
        }
    }
    
    // Pointer to unique implementation
    template<class T, class Deleter = void(*)(T*)>
    using unique_impl_ptr = std::unique_ptr<T, Deleter>;

    // Constructs an object of type T and wraps it and related default deleter in `unique_impl_ptr`
    template<class T, class... Args>
    inline unique_impl_ptr<T> make_unique_impl(Args&&... args) {
        static_assert(!std::is_array<T>::value, "unique_impl_ptr does not support arrays");

        return unique_impl_ptr<T>(
            new T(std::forward<Args>(args)...),
            &details::default_delete<T>);
    }
}


/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4040
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4040 : public IComponent {
        public:
            C4040();
            ~C4040();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4040_HPP_ */

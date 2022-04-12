/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4069
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4069 : public IComponent {
        public:
            C4069();
            ~C4069();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4069_HPP_ */

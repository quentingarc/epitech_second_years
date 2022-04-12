/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4017
*/

#ifndef C4017_HPP_
#define C4017_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4017 : public IComponent {
        public:
            C4017();
            ~C4017();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4017_HPP_ */

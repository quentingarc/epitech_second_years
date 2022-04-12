/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4094
*/

#ifndef C4094_HPP_
#define C4094_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4094 : public IComponent {
        public:
            C4094();
            ~C4094();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4094_HPP_ */

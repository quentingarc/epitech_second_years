/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4030 : public IComponent {
        public:
            C4030();
            ~C4030();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4030_HPP_ */

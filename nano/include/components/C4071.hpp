/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4071
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4071 : public IComponent {
        public:
            C4071();
            ~C4071();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4071_HPP_ */

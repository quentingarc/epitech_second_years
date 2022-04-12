/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C2716
*/

#ifndef C2716_HPP_
#define C2716_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C2716 : public IComponent {
        public:
            C2716();
            ~C2716();

            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C2716_HPP_ */

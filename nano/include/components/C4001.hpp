/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4001 : public IComponent {
        public:
            C4001();
            ~C4001();

            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4001_HPP_ */

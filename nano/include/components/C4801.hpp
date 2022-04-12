/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** C4801
*/

#ifndef C4801_HPP_
#define C4801_HPP_

#include <string>
#include "IComponent.hpp"

namespace nts {
    class C4801 : public IComponent {
        public:
            C4801();
            ~C4801();
    
            void simulate(std::size_t);
            nts::Tristate compute(size_t);
            void setLink(size_t, nts::IComponent &, size_t);
            void dump(void) const;
        protected:
        private:
    };
}

#endif /* !C4801_HPP_ */

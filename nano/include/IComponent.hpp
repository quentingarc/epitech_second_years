/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-quentin.garcia
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>

namespace nts {
    enum Tristate {
        TRUE = true,
        FALSE = false,
        UNDEFINED = (-true)
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t) = 0;
            virtual nts::Tristate compute(std::size_t) = 0;
            virtual void setLink(std::size_t, nts::IComponent &, std::size_t) = 0;
            virtual void dump() const = 0;
        protected:
        private:
    };
}
#endif /* !ICOMPONENT_HPP_ */

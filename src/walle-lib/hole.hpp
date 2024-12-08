#pragma once

#include "element.hpp"
#include "tree.hpp"


class Hole : public FixedElement {
    public:
        Hole(Environment *environment = nullptr, double x=0, double y=0);

        double get_depth() const;
        void set_depth(double depth);

        Tree* get_tree_inside() const;
        int set_tree_inside(Tree* tree);

        bool fit(Tree* tree) const;

        int update(double dt) override{return 0;}


    private:
        double depth_{0};
        Tree* tree_inside_{nullptr};
        static unsigned int id_counter;
};
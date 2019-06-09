#ifndef VISITOR_H
#define VISITOR_H

class Entity;
class Event;
class Conditional;

class Visitor {
    public:
        Visitor() {}
        virtual ~Visitor() {}

        virtual void visit(Entity*) {}
        virtual void visit(Event*) {}
        virtual void visit(Conditional*) {}

    private:
        Visitor(const Visitor&);
        Visitor& operator=(const Visitor&);
};

#endif // VISITOR_H

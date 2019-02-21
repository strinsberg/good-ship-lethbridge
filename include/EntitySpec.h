#ifndef CALRISSIEN_2720_ENTITYSPEC_H
#define CALRISSIEN_2720_ENTITYSPEC_H


class EntitySpec
{
  public:
    EntitySpec();
    virtual ~EntitySpec();
    bool matches(string);

    string getName();
    void setName(string);
    string getDescription();
    void setDescription(string);

  private:
    string name;
    string description;

    EntitySpec(const EntitySpec&);
    EntitySpec& operator=(const EntitySpec&);
};

#endif // ENTITYSPEC_H

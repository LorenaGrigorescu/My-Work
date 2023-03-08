using System.Collections;
using System.Collections.Generic;
using Lab8FacultativCS.model;

namespace Lab8FacultativCS.repository
{
    public interface IRepository<ID ,E> where E : Entitate<ID>
    {
        E FindOne(ID id);
        IEnumerable<E> FindAll();
        E Save(E e);
        E Delete(ID id);

    }
}
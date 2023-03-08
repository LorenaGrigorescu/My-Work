using System;

namespace Lab8FacultativCS.Properties.validator
{
    public class ExceptieValidare:ApplicationException
    {
        public ExceptieValidare(string message): base(message)
        {}
    }
}
using System;
using System.IO;
using Lab8FacultativCS.model;
using Lab8FacultativCS.Properties.validator;

namespace Lab8FacultativCS.repository
{
    public delegate E ParseLineEntity<E>(string line);
    public class FileRepository<ID,E> : InMemoryRepository<ID, E> where E: Entitate<ID>
    {
        protected string NumeFisier;
        protected ParseLineEntity<E> ParseLineEntity;

        public FileRepository(IValidator<E> validator, string numeFisier, ParseLineEntity<E> parseLineEntity):base(validator)
        {
            NumeFisier = numeFisier;
            ParseLineEntity = parseLineEntity;
            if (ParseLineEntity != null)
            {
                LoadFromFile();
            }
        }

        void LoadFromFile()
        {
            using (var fileStream = File.OpenRead(this.NumeFisier))
            using (var streamReader = new StreamReader(fileStream))
            {
                String line;
                while ((line = streamReader.ReadLine()) != null)
                {
                    E entitate = this.ParseLineEntity(line);
                    base.Save(entitate);
                }
            }
        }
        
    }
}
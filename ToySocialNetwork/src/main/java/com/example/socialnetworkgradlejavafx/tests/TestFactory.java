package com.example.socialnetworkgradlejavafx.tests;

public class TestFactory {

    static TestFactory instance;
    private  TestFactory(){}

    public static TestFactory getInstance()
    {
        if(instance==null)
            instance = new TestFactory();
        return instance;
    }
    public Test createTest(TestEnum testType)
    {
        if(testType.equals(TestEnum.REPOSITORY))
//            return new RepositoryTest();
            return null;
        return new ServiceTest();
    }
}

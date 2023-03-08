package com.example.socialnetworkgradlejavafx.validators;
import com.example.socialnetworkgradlejavafx.exception.ValidationException;

public interface Validators<T> {
     void validate(T t) throws ValidationException;

}

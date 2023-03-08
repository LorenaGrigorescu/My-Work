package com.example.socialnetworkgradlejavafx.exception;

public class ValidationExceptionCredentials extends Exception {
    public ValidationExceptionCredentials() {
    }

    public ValidationExceptionCredentials(String message) {
        super(message);
    }

    public ValidationExceptionCredentials(String message, Throwable cause) {
        super(message, cause);
    }

    public ValidationExceptionCredentials(Throwable cause) {
        super(cause);
    }

    public ValidationExceptionCredentials(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}

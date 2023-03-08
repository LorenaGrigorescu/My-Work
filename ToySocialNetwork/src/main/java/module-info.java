module com.example.socialnetworkgradlejavafx {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;
    requires java.sql;

    opens com.example.socialnetworkgradlejavafx to javafx.base,javafx.fxml;
//    opens com.example.socialnetworkgradlejavafx;
    exports com.example.socialnetworkgradlejavafx;
    exports com.example.socialnetworkgradlejavafx.controller;
    opens com.example.socialnetworkgradlejavafx.controller to javafx.base, javafx.fxml;
}
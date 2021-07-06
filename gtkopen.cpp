#include <gtkmm.h>

struct GtkOpenApplication : Gtk::Application {
    GtkOpenApplication() : Gtk::Application("", Gio::APPLICATION_HANDLES_OPEN) {}

    void on_open(const Gio::Application::type_vec_files& files, const Glib::ustring&) override {
        auto dialog = Gtk::AppChooserDialog(files.front());
        int response = dialog.run();
        if (response == Gtk::RESPONSE_OK)
            dialog.get_app_info()->launch(files);
    }
};

int main (int argc, char *argv[])
{
    return GtkOpenApplication().run(argc, argv);
}
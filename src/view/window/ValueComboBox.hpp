#ifndef _VALUE_COMBO_BOX_
#define _VALUE_COMBO_BOX_


#include <gtkmm.h>

namespace protobuf_decoder
{
    class ValueComboBox : public Gtk::ComboBox
    {
    public:
        ValueComboBox() {}
        ValueComboBox(const std::vector<std::string>& iValues);
        
        class ModelColumns : public Gtk::TreeModel::ColumnRecord
        {
        public:
            ModelColumns() { add(_name); }

            Gtk::TreeModelColumn<Glib::ustring> _name;
        };
        
        ModelColumns _columns;

        Glib::RefPtr<Gtk::ListStore> _refTreeModel;
    };
}

#endif //_VALUE_COMBO_BOX_

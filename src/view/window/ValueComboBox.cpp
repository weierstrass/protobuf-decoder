#include "ValueComboBox.hpp"

namespace protobuf_decoder
{
    
    ValueComboBox::ValueComboBox(const std::vector<std::string>& iValues)
    {
        // Set up tree model.
        _refTreeModel = Gtk::ListStore::create(_columns);
        set_model(_refTreeModel);

        // Fill rows with values. 
        for (auto aValue : iValues)
        {
            Gtk::TreeModel::Row row = *(_refTreeModel->append());
            row[_columns._name] = aValue;
            set_active(row);
        }
        
        pack_start(_columns._name);

        set_margin_bottom(20);
        
    }
}

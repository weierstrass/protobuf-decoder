#include "ValueComboBox.hpp"

#include <iostream>

namespace protobuf_decoder
{
    
    ValueComboBox::ValueComboBox(const std::vector<std::string>& iValues)
    {

        setValues(iValues);
        
        set_margin_bottom(20);
        
    }

    void ValueComboBox::setValues(const std::vector<std::string>& iValues)
    {

        // Set up tree model.
        _refTreeModel = Gtk::ListStore::create(_columns);
        set_model(_refTreeModel);

        std::cout << "ABAB1" << std::endl;
        _refTreeModel->clear();
     
        std::cout << "ABAB1" << std::endl;   
        // Fill rows with values.
        for (auto aValue : iValues)
        {
            
            std::cout << "ABAB1" << std::endl;
            Gtk::TreeModel::Row row = *(_refTreeModel->append());
            row[_columns._name] = aValue;
            //set_active(row);
        }
        
        clear();
        pack_start(_columns._name);

    }

    std::string ValueComboBox::getActive()
    {
        Gtk::TreeModel::iterator iter = get_active();
        if(iter)
        {
            Gtk::TreeModel::Row row = *iter;
            if(row)
            {
                
                Glib::ustring aValue = row[_columns._name];
                return aValue;
            }
        }

        return "";
    }
}

#ifndef TEXT_AREA_BASE_H
#define TEXT_AREA_BASE_H

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>

namespace protobuf_decoder
{

    /**
     * @breif Base containing common attributes for text areas.
     */
    class TextAreaBase : public Gtk::ScrolledWindow
    {
    public:
        /**
         * @brief Constructor
         */
        TextAreaBase();

        /**
         * @brief Destructor
         */
        virtual ~TextAreaBase() {}

        /**
         * @brief Getter for the text of text area.
         *
         * @return std::string The text of the text area.
         */
        std::string getText() const;

        /**
         * @brief Setter for the text of the text area.
         *
         * @param iText Text to set to the text area.
         */
        void setText(const std::string& iText);

        /// TextView containing the text of the text area.
        Gtk::TextView _textView;

    };

}

#endif //TEXT_AREA_BASE_H

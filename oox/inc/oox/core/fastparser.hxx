/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef OOX_CORE_FASTPARSER_HXX
#define OOX_CORE_FASTPARSER_HXX

#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/xml/sax/XFastParser.hpp>

namespace oox {
    struct NamespaceMap;
    class StorageBase;
}

namespace oox {
namespace core {

// ============================================================================

/** Wrapper for a fast SAX parser that works on automatically generated OOXML
    token and namespace identifiers.
 */
class FastParser
{
public:
    explicit            FastParser(
                            const ::com::sun::star::uno::Reference< ::com::sun::star::uno::XComponentContext >& rxContext )
                            throw( ::com::sun::star::uno::RuntimeException );

    virtual             ~FastParser();

    /** Registers an OOXML namespace at the parser. */
    void                registerNamespace( sal_Int32 nNamespaceId )
    		                throw( ::com::sun::star::lang::IllegalArgumentException, ::com::sun::star::uno::RuntimeException );

    /** Sets the passed document handler that will receive the SAX parser events. */
    void                setDocumentHandler(
                            const ::com::sun::star::uno::Reference< ::com::sun::star::xml::sax::XFastDocumentHandler >& rxDocHandler )
    		                throw( ::com::sun::star::uno::RuntimeException );

    /** Parses the passed SAX input source.
        @param bCloseStream  True = closes the stream in the input source after parsing. */
    void                parseStream( const ::com::sun::star::xml::sax::InputSource& rInputSource, bool bCloseStream = false )
                            throw( ::com::sun::star::xml::sax::SAXException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException );

    /** Parses the passed input stream.
        @param bCloseStream  True = closes the passed stream after parsing. */
    void                parseStream(
                            const ::com::sun::star::uno::Reference< ::com::sun::star::io::XInputStream >& rxInStream,
                            const ::rtl::OUString& rStreamName, bool bCloseStream = false )
                            throw( ::com::sun::star::xml::sax::SAXException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException );

    /** Parses a stream from the passed storage with the specified name.
        @param bCloseStream  True = closes the stream after parsing. */
    void                parseStream( StorageBase& rStorage, const ::rtl::OUString& rStreamName, bool bCloseStream = false )
                            throw( ::com::sun::star::xml::sax::SAXException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException );

private:
    ::com::sun::star::uno::Reference< ::com::sun::star::xml::sax::XFastParser >
                        mxParser;
    const NamespaceMap& mrNamespaceMap;
};

// ============================================================================

} // namespace core
} // namespace oox

#endif

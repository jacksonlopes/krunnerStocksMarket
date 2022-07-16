add_definitions(-DTRANSLATION_DOMAIN=\"plasma_runner_org.kde.krunnerstocksmarket\")

add_library(krunner_stocksmarket MODULE)

target_sources(krunner_stocksmarket PRIVATE
    krunnerStocksMarket.cpp
    smconnect.cpp
    smprice.cpp
)

kcoreaddons_desktop_to_json(krunner_stocksmarket plasma-runner-krunnerstocksmarket.desktop)
find_package(Qt5Network REQUIRED)
target_link_libraries(krunner_stocksmarket KF5::Runner KF5::I18n Qt5::Network Qt5::Widgets)

install(TARGETS krunner_stocksmarket DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/krunner)

install(FILES plasma-runner-krunnerstocksmarket.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})

/**
 * @file selector.hpp
 * @brief Robodash Selector
 * @ingroup selector
 */

#pragma once
#include "robodash/api.h"
#include <functional>
#include <string>
#include <vector>

namespace rd {

/**
 * @defgroup selector Selector
 * @brief A function selector
 * @image html selector.png
 *
 * A function selector for easily managing autonomous routines. If available, automatically saves
 * the current configuration to an SD card and loads it on the next run. Also supports displaying
 * images from the SD card.
 */

/**
 * @brief Selector class
 * @ingroup selector
 */
class Selector {
	/// @addtogroup selector
	/// @{
  public:
	/// @name Selector Typedefs
	typedef std::function<void()> routine_action_t;

	typedef struct routine {
		std::string name;
		routine_action_t action;
		std::string img = "";
	} routine_t;

	/// @name Selector Functions

	/**
	 * @brief Create autonomous selector
	 * @param name Name of the autonomous selector
	 * @param autons Vector of autonomous rotuines
	 */
	Selector(std::string name, std::vector<routine_t> autons);

	/**
	 * @brief Create autonomous selector
	 * @param autons Vector of autonomous rotuines
	 */
	Selector(std::vector<routine_t> autons);

	/**
	 * @brief Run selected auton
	 */
	void run_auton();

	/**
	 * @brief Set this view to the active view
	 */
	void focus();

	/// @}

  private:
	rd_view_t *view;

	lv_obj_t *select_cont;
	lv_obj_t *selected_label;
	lv_obj_t *selected_img;

	std::string name;
	std::vector<rd::Selector::routine_t> routines;
	rd::Selector::routine_t *selected_routine;

	void sd_save();
	void sd_load();

	static void select_cb(lv_event_t *event);
};

} // namespace rd